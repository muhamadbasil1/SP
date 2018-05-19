import requests
from PIL import Image
from bs4 import BeautifulSoup
from StringIO import StringIO
import os
from datetime import datetime
def getQariNames(URL):
 
	req = requests.get(URL)
	img_links = []
	if req.status_code == 200:
		parser_obj = BeautifulSoup(req.content, "html.parser")
		img_tag_list = parser_obj.find_all("a")
		for img_tag in img_tag_list:
			if img_tag['href'] != "../" and img_tag['href'] !="iza3a.zip":
				img_links.append(img_tag['href'])
	return img_links
 
def download_mp3(url_list):
	keys = []
	values = []
	qariNo = 1
	for mp3_url in url_list:
		url="https://download.quranicaudio.com/quran/"+mp3_url
		audio_list = getQariNames("https://download.quranicaudio.com/quran/"+mp3_url)
		os.system("mkdir -p %s" % mp3_url)
		os.system("mkdir -p "+mp3_url+"a")
		count = 0
		d = datetime.now()
		str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
		os.system("echo "+str+" Start Processing "+ `qariNo` +" out "+ `len(url_list)`+" >>logfile.txt")
		os.system("echo "+str+" "+ mp3_url +"  >>logfile.txt")
		for audio in audio_list:
			if ".mp3" in audio:
				a=audio.split("/")[-1]
				if count >= (len(audio_list)-3):
					req = requests.get(url+audio,stream=True)
					d = datetime.now()
					str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
					os.system("echo "+str+" "+ mp3_url +" "+ audio+ " START  >>logfile.txt")
					with open(mp3_url+"a/"+audio,"w+") as f:
						f.write(req.content)
					d = datetime.now()
					str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
					os.system("echo "+str+" "+ mp3_url +" "+ audio+ " END  >>logfile.txt")
				count+=1
		d = datetime.now()
		str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
		os.system("echo "+str+" Merging the Files of "+ mp3_url +" START  >>logfile.txt")
		output = mp3_url+'second_Half.mp3'
		files = mp3_url+"a/"
		os.system("mp3wrap " + output + " %s*.mp3" % files+ " >/dev/null")
		os.system("rm -r "+files)
		d = datetime.now()
		str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
		os.system("echo "+str+" Merging the Files of "+ mp3_url +" END >>logfile.txt")
		qariNo+=1
def main():
	URL = "https://download.quranicaudio.com/quran/"
	url_list = getQariNames(URL)
	os.system("touch logfile.txt")
	d = datetime.now()
	str = datetime.strftime(d,"%Y-%m-%d %H:%M:%S")
	os.system("echo "+str+" Total Qari %d >>logfile.txt" %len(url_list))
	download_mp3(url_list)
	
main()
