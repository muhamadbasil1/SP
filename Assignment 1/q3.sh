Is_lower()
{
	str=$1
	echo ${str,,}
}
Is_root()
{
		if [ `id -u` -eq 0 ]
		then
			return 1
		else
			return 0
		fi
}
Is_user_exists()
{
	x=$1
	grep -w "$x" /etc/passwd >/dev/null
	if [ $? -eq 0 ]
	then
		return 1
		
	else
		return 0
	fi
}

Is_lower "Muhammad Basil"
Is_root 
if [ $? -eq 1 ]
then
	echo "Root"
else
	echo "Normal User"
fi
Is_user_exists uzair
if [ $? -eq 1 ]
then
	echo "User Exists"
else
	echo "User does not Exists"
fi
