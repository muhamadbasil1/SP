import requests
from bs4 import BeautifulSoup
from StringIO import StringIO
 
 
def get_all_articles(URL):
	req = requests.get(URL)
	h2_list = []
	a_list = []
	links = []
	if req.status_code == 200:
		parser_obj = BeautifulSoup(req.content, "html.parser")
		article_tag_list = parser_obj.find_all("article")
		for article_tag in article_tag_list:
			h2_list= article_tag.find_all("h2")
			for h2_tag in h2_list:
				a_list= h2_tag.find_all("a")
				for a_tag in a_list:
					links.append(a_tag["href"])
	return links
 
def search_links(url_list,word):
	p_list =[]
	matched = []
	for news_url in url_list:
		news_req = requests.get(news_url,stream =True)
		parser_obj = BeautifulSoup(news_req.content, "html.parser")
		for div in parser_obj.find_all("div",{"class":"the-post-content"}):
			p_list = div.find_all("p")
		str1=""
		for p_tag in p_list:
			str1 = str1 + p_tag.get_text()
		str1=str1.lower()
		l = str1.split(" ")
		for i in l:
			if i==word:
				matched.append(news_url)
				break
	return matched

def main():
	print "Enter Words (Space Separated): "
	str = raw_input()
	str=str.lower()
	l = str.split(" ")
	for k in range(1,6):
		URL = "https://propakistani.pk/category/sports/page/%d" %k
		url_list = get_all_articles(URL)
		matched = []
		for i in l:
			print i+" in page %d: " %k
			matched = search_links(url_list,i)
			if len(matched)==0:
				print "No URL Found in %d! " %d
			else:
				for j in matched:
					print j
	
main()
