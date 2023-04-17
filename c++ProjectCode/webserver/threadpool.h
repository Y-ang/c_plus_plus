#ifndef THREADPOOL.H
#define THREADPOOL.H

#include <pthread.h>
#include <list>
#include "locker.h"
#include <exception>
#include <cstdio>



// 线程池类，定义成模板类方便代码复用，任务用模版的方式
template<typename T>
class threadpool {
public:
    threadpool(int thread_number = 8, int max_requests = 10000);
    ~threadpool();
    bool append(T* request);
    void run();

private:
    static void* worker(void* arg);

private:
    // 线程数量
    int m_thread_number;
    // 线程池数组，大小为线程的数量
    pthread_t * m_threads;

    // 请求队列中最多允许的，等待处理的请求数量
    int m_max_requests;

    // 请求队列
    std::list<T*> m_workqueue;

    // 互斥锁
    locker m_queuelocker;

    // 信号量 用来判断是否有任务需要处理
    sem m_queuestat;

    // s是否结束线程
    bool m_stop;

};

template<typename T>
threadpool<T>::threadpool(int thread_num, int max_requests) :
    m_thread_number(thread_num), 
    m_max_requests(max_requests) 
    m_stop(false), m_threads(NULL) {
        if (thread_num <= 0 || max_requests <= 0) {
            throw std::exception
        }

        m_threads = new pthread_t[m_thread_number];
        if (!m_threads) {
            throw std::exception;
        }

        // 创建thread_number个线程， 并将它们设置为线程脱离（子线程执行完后系统自动回收资源，不必等到父进程来回收资源）
        for (int i = 0; i < m_thread_number; ++i) {
            printf("create the %dth thread")
            if (pthread_create(m_threads + i, NULL, worker, NULL) != 0) {// c++z中worker必须是静态函数
                delete [] m_threads;
                throw std::exception();
            }

            if (pthread_detach(m_threads[i])) {
                delete [] m_threads;
                throw std::exception();
            }

        }

    }

template<typename T>
threadpool<T>::~threadpool() {
    delete [] m_threads;
    m_stop = true;
}

template<typename T> 
bool threadpool<T>::append(T* request) {
    m_queuelocker.lock();

    // 工作队列已经超过最大申请数
    if (m_workqueue.size() > m_max_requests) {
        m_queuelocker.unlock();
        return false;
    }

    // 没有超多最大任务数，将任务添加到工作队列中
    m_workqueue.push_back(request);
    m_queuelocker.unlock();   // 解锁
    m_queuestat.post();       // 工作队列+1，信号量+1
    return true;
}

template<typename T>
void* threadpool<T>::worker(void* arg) {
    threadpool * pool = (threadpool *)arg;
    pool->run();
    return pool;
}

template<typename T>
void threadpool<T>::run() {
    while (!m_stop) {
        m_queuestat.wait();   // 信号量有值就不阻塞，信号量减一；否则阻塞
        m_queuelocker.lock(); // 有任务，上锁
        if (m_workqueue.empty()) {
            m_queuelocker.unlock();
            continue;
        }
        // 获取任务
        T* request = m_workqueue.front();
        m_workqueue.pop_front();
        m_queuelocker.unlock();
        if (!request) {
            continue;
        }

        // 获取到任务，执行任务
        request->process();
    }
}


#endif