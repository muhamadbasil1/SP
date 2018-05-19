def findMat(array,mat):
	numbers = [0,1,2,3,4,5,6]
	for i in numbers:
		for j in numbers:
			if array[i][j]==mat[0][0] and array[i+1][j]==mat[1][0] and array[i][j+1]==mat[0][1] and array[i+1][j+1]==mat[1][1]:
				return i,j
				
				
	return -1,-1
	


def main():
	array = [[1,2,3,4,5,6,7,8],
			[4,2,2,4,5,6,7,4],
			[0,7,9,2,5,6,7,8],
			[5,7,3,4,5,6,7,8],
			[7,6,7,6,5,6,7,8],
			[9,9,9,9,9,9,9,9],
			[1,2,3,4,5,6,7,8],
			[0,2,3,4,5,6,7,8]]
	mat = [[9,9],[4,5]]
	i,j=findMat(array,mat)
	print "i: "+`i`+" j: "+`j`		

main()		
