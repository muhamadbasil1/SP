str=raw_input("Enter string: ")
alpha=0
digit=0
for i in str:
	if i.isalpha():
		alpha+=1
	elif i.isdigit():
		digit+=1
		
print "Alphabets: " , alpha, "Digits: ", digit
