# 0
Hi, everyone 
My name is Jing yang from Huazhong University of Science & Technology in China. 
Welcome to my presentation on Isolating Compiler Optimization Faults via Differentiating Finer-grained Options
This work is cooperated with Nanjing University,  main advised by Dr.Yibiao Yang and Prof. Ming Wen.

# 1
First, I’m going to talk about compiler optimization bugs and the importance of locating them.   

Compilers are the most fundamental infrastructures in software development.  
However, being complex software systems, compilers themselves are prone to errors.   

Among those bugs, compiler optimization bugs account for the largest proportion.  
When compiler produce different results under different optimization options, optimization bug occurs. 
Optimization bugs can lead to unpredictable errors with the bug-triggering optimization options 
and make it difficult for program developers to find the cause of the errors  

Thus, one of the most important tasks for developers is to locate and fix optimization bugs in compilers. 
Nevertheless, locating compiler bugs is challenging as compilers are one of the largest software systems. 
Driven by this, it is of significant importance to advance the techniques for locating bugs of compiler optimizations. 

# 2
Recently, Chen et al. proposed DiWi [2] and RecBi [3] to facilitate compiler bug isolation.

They introduced a novel concept of witness test programs,  which are mutated from the bug-triggering test programs of the compiler. 

The witness test programs can be viewed as the passing test programs in the Spectrum-Based Fault Localization (SBFL) techniques 

Then the tools can compute suspicious values of compiler elements.

RecBi and DiWi still encounter limitations. 

First, the goal of the existing approaches is to generate passing test programs which will not produce multiple failing coverage of compilers.

Second, generating passing test programs is time-consuming as it is hard to obtain witness test programs without a large amount of attempts in program mutation. 

Third, the localization results are not reliable due to the randomness of the mutated programs. 

In our work, we therefore propose a simple yet effective and efficient fault localization approach to locate optimization bugs，via differentiating finer-grained options.


# 3
So, What is the Finer-grained option?

Fisrt, the overall compiler optimization level is controlled by the command line option -On, where n is the required optimization level, as follows:
-O0 –O1 –O2 –O3 and so on
Each optimization level supports multiple optimizations.

That means, compilers support multiple fine-grained optimization options under each coarse-grained optimization level

Take GCC for example, the finer-grained option –foptimize hyphen strlen and so on are enabled by default at the coarser-grained optimization level O2.

and each fine-grained option can be enabled or disabled manually. For example, we can disable the –foptimize-strlen by replacing the f with fno hyphen


# 4
Here, we use an example to illustrate the motivation of utilizing optimization option configuration in fault localization of compilers.
This figure shows the real bug of GCC, where the left is the reported bug-triggering test program and the right is the corresponding compiler option configurations.
From the figure, we can find that the output of the test program under the optimization levels “-O1” and “-O2” is 6.
However, under the optimization level “-O3”, the output is a different value 0, thus triggering a bug in the compiler GCC.
In addition, when the finer-grained optimization option is disabled, the output of the test program turns to be correct as the reslut is changed to 6.
When disabling the other fine-grained option, the output of the test program is still failing.
Since the result is flipped when we disable the option, we call it the bug-related option
On the contrary, we call “-fpeel-loops” a bug-free option


# 5
Accordingly, the first optimization configuration is a passing optimization configuration, since it produces correct result.
And the second optimization configuration is a failing optimization configuration.

So, with the identified finer-grained bug-related and bug-free options, we are able to obtain multiple passing and
failing optimization configurations by enabling or disabling some of those fine-grained options.

Meanwhile, we can obtain the coverage information of compilers for each of the passing or failing optimization configurations.


# 6
We further analyze whether more effective failing and passing coverage information can be obtained by configuring optimization options.
# 7
Here， is our observation on the effect of configuring diverse numbers of compiler optimizations on compiler coverage.

We incrementally disable fine-grained optimization options under the bug-triggering optimization level of the compiler.

using an GCC compiler as an example. 
The figure shows the effect of using different numbers of optimizations on the number of lines and files covered in compilers.
The x-axis of the figure is the number of fine-grained optimizations that were turned off, and the number ranges from 1 to 120. 
The left Y-axis is the number of lines covered in the compiler, reducing from about 86,000 to about 53,000. 
The right y-axis is the number of files covered in the compiler, which decreases from about 300 files to about 278 files.

From this figure, we observed that the more optimizations are disabled, the fewer code elements are covered in compilers. 
That means, disabling more optimization options can simplify the coverage information of compilers to a great extent. 

Furthermore, applying this observation to obtaining failing coverage information helps to eliminate many innocent code elements from suspicious ones.

Following the observation, we design a novel fault localization approach of compilers via differentiating fine-grained optimization options, named ODFL.


# 8
Following the observation, we design a novel fault localization approach of compilers via differentiating fine-grained optimization options, named ODFL.

Next, we present an overview of ODFL.

In ODFL, we search several effective failing optimization configurations and passing optimization configurations, and then compare their compiler coverage similar to SBFL to locate compiler bugs.

Thus, there are two key issues to the success of ODFL. 
First, from the previous observation, we know that using fewer optimizations to compile programs makes the code coverage of compilers reduced. 
Thus, the failing optimization configurations should enable as few optimizations as possible.

Meanwhile, the passing coverage sharing similar execution traces with the failing coverage of compilers is also helpful to eliminate innocent files from being suspected.


# 9
However, there are hundreds of the fine-grained optimization options under each coarse-grained optimization level in compilers, making the process of differentiating optimization configurations via exhaustive search impossible.
In this case, bug-free and bug-related options serve as basic elements in the initial search space with the aim to reduce search cost.
ODFL first initializes the configuration by disabling all bug-free options and enabling all bug-related options. 
This is because it can use fewer optimizations to trigger bugs with the highest probability in this way.
Also, ODFL follows the principle that searching for the failing configuration first, and then identifying the passing configurations that enable similar optimizations to the failing one.
At the same time, ODFL operates on the fine-grained options based on the initial configuration

# 10
Specifically, each optimization configuration produces two types of results (passing and failing), correspondingly, the search process can be summarized into the following three operations:
For the first and the second conditions, ODFL disables those enabled options with combinatorial search for the next configuration, until sufficient passing configurations are found.
When one or more failing configurations are found during the process, the new ones are added to the failing configuration set since they contain fewer enabled options. 
If the compilation result is passing under the current optimization configuration and the failing configuration has never been found yet, ODFL enables those disabled options with combinatorial search for the next configuration until it finds the first failing optimization configuration.
ODFL then performs the first operation to search passing and failing optimization configurations.
Here, effective passing and failing configurations can be searched according to the above three operations via achieving two search goals

# 11
According to the failing and passing configurations we collected, ODFL adopts the SBFL formula to compute the suspicious value for each touched statement.
Different from prior work, we introduce multiple failing coverage in this study. 
Then, ODFL aggregates the suspicious values of all statements in a source file to represent file’s suspicious value.
Finally, ODFL generates a ranking list of compiler files based on the suspicious value of each compiler file in reverse order.


# 12
To evaluate the effectiveness of ODFL, 60 real GCC bugs in the released benchmark are used for evaluation.
To evaluate the results from different aspects, we measure the following metrics that are widely-used by the existing work
Then, we compare our approach with the state-of the art approached : RecBi and DiWi
Also, to evaluate the contributions of the components of ODFL, we designed three variants
ODFLwf : replaces failing configurations with bug-triggering optimization level 
ODFLwp replaces passing configurations with passing programs RecBi mutates
ODFLwfp replaces both the failing and passing optimization configurations with the bug-triggering and bug-free optimization levels


# 13
Here, is the comparison results.
From the table, we can see ODFL performs much better then RecBi

# 14
Also, we compare ODFL with DiWi
From the table we can see, ODFL locate 200% more bugs than DiWi within the top-1 file.

# 18
We further studied how different formulae affect the performance of ODFL. 
The left table shows the six formulas we compared,
The right table presents the results of ODFL using different formulae. 
In this table, different rows represent the different SBFL formulae utilized and different columns represent the different metrics evaluated

From the result, we know that

# 19
Here, We discuss the efficiency of our ODFL by comparing the time consumed.
Specifically, we evaluated the time required for each component and entire process in ODFL.
The Entire process includes initialize the option set, search configurations and collect the compiler coverage
Since RecBi repeated 5 times to reduce the influence of randomness, the overall experiment of RecBi took 5 hours.
Thus, compared with the state-of-the-art approach RecBi, ODFL only consumes about 12% of the time of RecBi

# 20
In conclusion, 
