from termcolor import colored

file_1 = open('./out.txt', 'r')
file_2 = open('./expected.txt', 'r')

lines1 = file_1.readlines();
lines2 = file_2.readlines();

diff =[]
test =[]

for i in range(len(lines2)):
	if(lines2[i] != lines1[i]):
		diff.append([lines1[i], lines2[i]])
		test.append(i+1)

if(len(diff) == 0):
	print(colored('Accepted', 'green', attrs=['bold']))
else:
	print(colored('________________________________________', 'red', attrs=['bold']))
	print(colored('Wrong Answer', 'red', attrs=['bold']))
	print(colored('________________________________________', 'red', attrs=['bold']))
	print()
	for i in range(len(diff)):
		print(colored("On test #"+str(test[i])+":", 'green', attrs=['bold']))
		for j in range(min(len(diff[i][0]), len(diff[i][1]))):
			if(diff[i][0][j] != diff[i][1][j]):
				print(colored(diff[i][0][j], 'red', attrs=['bold']), end="")
			else:
				print(diff[i][0][j], end="")
		if(len(diff[i][0]) > len(diff[i][1])):
			for j in range(len(diff[i][1]), len(diff[i][0])):
				print(diff[i][0][j], end="")
		for j in range(min(len(diff[i][0]), len(diff[i][1]))):
			if(diff[i][0][j] != diff[i][1][j]):
				print(colored(diff[i][1][j], 'green', attrs=['bold']), end="")
			else:
				print(diff[i][0][j], end="")
		if(len(diff[i][0]) < len(diff[i][1])):
			for j in range(len(diff[i][0]), len(diff[i][1])):
				print(diff[i][1][j], end="")
		print()

		print("===========================")
		print()

file_1.close()
file_2.close()
