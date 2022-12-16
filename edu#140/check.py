from termcolor import colored

file_1 = open('/home/mouad/Documents/cp/edu#140/out.txt', 'r')
file_2 = open('/home/mouad/Documents/cp/edu#140/expected.txt', 'r')

diffs = [[]]
test = []

for i in range(len(lines2)):
	s1 = ' '.join(.split())
	s2 = ' '.join(lines2[i].split())
	if(s1 != s2):
		diffs.append([s1, s2])
		test.append(i+1)

if(len(diffs) == 0):
	print(colored('Accepted', 'green'))
else:
	print(colored('Wrong Answer', 'red'))
	print("============================")

	print(diffs)


file_1.close()
file_2.close()