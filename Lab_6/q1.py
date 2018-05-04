def generate_numbers():
	l=[]
	for i in range(2000,3200):
		if i%7==0 and i%5!=0:
			l.append(i)
	return l
print generate_numbers()
