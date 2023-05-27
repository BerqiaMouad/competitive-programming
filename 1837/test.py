from termcolor import colored
import sys 
import os
import difflib


if __name__ == "__main__":

    # get the problem name from the first argument
    problem_name = sys.argv[1]

    # test the c++ program on the testsets that are in the directory with the name of the problem 
    os.system("g++ -o " + problem_name + " " + problem_name + ".cpp")

    # get the list of testsets
    testsets = os.listdir(problem_name)
    
    # keep only the input files
    testsets = [testset for testset in testsets if testset[:2] == "in"]

    # for each testset
    i = 1
    for testset in testsets:
        #run the program on the testset
        os.system(problem_name + ".exe < " + problem_name + "/" + testset + " > " + problem_name + "/" + testset[:len(testset)-4] + ".out")
        
        output = ""
        expected_output = ""

        # get the output of the program
        with open(problem_name + "/" + testset[:len(testset)-4] + ".out", "r") as f:
            output = f.read()
    
        # get the expected output
        with open(problem_name + "/out" + str(i) + ".txt", "r") as f:
            expected_output = f.read()

        # compare the output of the program with the expected output
        if output == expected_output:
            print("Test " + str(i), end = ": ")
            print(colored("OK ✓", "green"))

        else:
            print("Test " + str(i), end = ": ")
            print(colored("Failed ✗", "red"))
            print()

            print(colored("Expected output:", "red"))
            print(expected_output)
            print()

            print(colored("Output:", "red"))
            print(output)
            print()
          

        # remove the output file
        os.chdir(problem_name)
        os.system("del " + testset[:len(testset)-4] + ".out")
        os.chdir("..")

        i += 1

    # remove the executable
    os.system("del " + problem_name + ".exe")

    
