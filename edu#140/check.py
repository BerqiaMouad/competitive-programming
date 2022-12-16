from termcolor import colored

file_1 = open('/home/mouad/Documents/cp/edu#140/out.txt', 'r')
file_2 = open('/home/mouad/Documents/cp/edu#140/expected.txt', 'r')

lines1 = file_1.readlines();
lines2 = file_2.readlines();

diff =[]
test =[]

for i in range(len(lines2)):
	if(lines2[i] != lines1[i]):
		diff.append([lines1, lines2])
		test.append(i+1)

if(len(diff) == 0):
	print(colored('Accepted', 'green', attrs=['bold']))
else:
	print(colored('Wrong Answer', 'red', attrs=['bold']))
	print("++++++++++++++++++++++++++++")
	print()
	for i in range(len(diff)):
		print("On test #"+str(test[i])+":")
		print(diff[i][0])
		print(diff[i][1])
		print("===========================")

file_1.close()
file_2.close()
