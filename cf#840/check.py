from termcolor import colored

file_1 = open('./out.txt', 'r')
file_2 = open('./expected.txt', 'r')

lines1 = file_1.readlines();
lines2 = file_2.readlines();

diff =[]
test =[]

for i in range(len(lines2)):
	if(lines2[i] != lines1[i]):
		diff.append([lines1, lines2])
		test.append(i+1)

if(len(diff) == 0):
	print(colored('Passed ✓', 'green', attrs=['bold']))
else:
	print(colored('Wrong Answer ✗', 'red', attrs=['bold']))
	print("++++++++++++++++++++++++++++")
	print()
	for i in range(len(diff)):
		print("On test #"+str(test[i])+":")
		print()
		print(colored('Output', attrs=['bold']))
		print()
		for j in diff[i][0]:
			print(j, end="")
		print("\n===========================")
		print(colored('Expected', attrs=['bold']))
		print()
		for j in diff[i][1]:
			print(j, end="")
		print("\n===========================")

file_1.close()
file_2.close()
