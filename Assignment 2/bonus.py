import requests
from textblob import TextBlob
from bs4 import BeautifulSoup
def get_brand_names(URL):
	brand_dict={}
	req = requests.get(URL)
	if req.status_code == 200:
		parser_obj= BeautifulSoup(req.content,"html.parser")
	
		div_tag=parser_obj.find("div",{"class":"brandmenu-v2"})
		li_list =div_tag.find_all("li")
		for li in li_list:
			a=li.find("a")
			val=a.text
			val=val.lower()
			brand_dict[val] = a["href"]
		
	return brand_dict

def get_particular_brand_models(URL):
	models_dict={}
	req = requests.get(URL)
	if req.status_code == 200:
		parser_obj= BeautifulSoup(req.content,"html.parser")
	
		div_tag=parser_obj.find("div",{"class":"makers"})
		li_list =div_tag.find_all("li")
		for li in li_list:
			a=li.find("a")
			name=li.find("span")
			n=name.text
			n=n.lower()
			models_dict[n]=a["href"]
	return models_dict
	
def get_comments(URL):
	count=0
	polarity=0
	brand_list=[]
	req = requests.get(URL)
	if req.status_code == 200:
		parser_obj= BeautifulSoup(req.content,"html.parser")
	
		p_tag_list=parser_obj.find_all("p",{"class":"uopin"})
		for p_tag in p_tag_list:
			count+=1
			sent=TextBlob(p_tag.text)
			polarity += sent.sentiment.polarity
	return (polarity/count)*100
def main():
	str = raw_input("Enter Brand Name: ")
	str=str.lower()
	str1 = raw_input("Enter Model Name: ")
	str1=str1.lower()
	flag=1
	URL="https://www.gsmarena.com/"
	brand_dict=get_brand_names(URL)
	for index,val in brand_dict.items():
		if index == str:
			flag=0
			models_dict = get_particular_brand_models(URL+val)
			for i,v in models_dict.items():
				if i==str1:
					flag=2
					print "Polarity = %d percent" %get_comments(URL+v)
	if flag==1:		
		print "Brand not Found!"
	elif flag==0:
		print "Model not Found!"

main()	
