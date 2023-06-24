import os
import sys

import werkzeug
werkzeug.cached_property = werkzeug.utils.cached_property
from robobrowser import RoboBrowser

import time
from termcolor import colored



if __name__ == '__main__':

    # Get the contest number form the name of the current directory
    contestNumber = os.getcwd().split('\\')[-1]
    
    problemName = sys.argv[1]

    contestUrl =  'https://codeforces.com/contest/' + contestNumber + '/submit/' + problemName

    # use browser to submit a code to the problem
    browser = RoboBrowser(parser='html.parser')

    # login before submitting the code
    browser.open('https://codeforces.com/enter?back=%2F')

    # get the login form
    loginForm = browser.get_form(id='enterForm')

    # fill the login form
    loginForm['handleOrEmail'].value = 'nop'
    loginForm['password'].value = 'nop'

    # submit the login form
    browser.submit_form(loginForm)

    # check if the login was successful
    if browser.url != 'https://codeforces.com/':
        print(colored('Login failed', 'red'))
        exit(0)

    # go to the problem page using the same browser
    browser.open(contestUrl)

    # check if the problem exists
    if browser.url != contestUrl:
        print(colored('Problem does not exist', 'red'))
        exit(0)

    
    # get the submit form
    submitForm = browser.get_form(class_='submit-form')


    # fill the submit form, send the code as a file
    submitForm['sourceFile'].value = open(problemName + '.cpp', 'rb')



    # submit the form
    browser.submit_form(submitForm)

    # get the current status of the submission
    statusUrl = browser.url

    status = browser.find(class_='status-verdict-cell').text

    # wait until the submission is done
    
    # check if status contains 'In queue' or 'Running'

    while "In queue" in status or "Running" in status:
        #os.system('cls')
        status = status.split()
        status = ' '.join(status)
        #print(colored(status, 'yellow'))
        browser.open(statusUrl)
        status = browser.find(class_='status-verdict-cell').text

    # print the final status
    #os.system('cls')
    if "Accepted" in status or "Pretests" in status:
        status = status.split()
        status = ' '.join(status)
        print()
        print()
        print(colored(status, 'green'))
        print()
    else:
        status = status.split()
        status = ' '.join(status)
        print()
        print()
        print(colored(status, 'red'))
        print()


