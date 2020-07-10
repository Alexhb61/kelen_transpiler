from requests import post, get
from bs4 import BeautifulSoup, UnicodeDammit
import re
import chardet
import time
#CODE FAILURES
# err_str = r"āēīōūñŋþλ"
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson
#setup constant like things
url = "https://www.terjemar.net/kelen/Dict/dictlisting.php"
urlStem = "https://www.terjemar.net/kelen/Dict/"
not_word = re.compile('-')
is_noun = re.compile('\[N')
is_stem = re.compile('-.+-')
find_whitespace = re.compile('\s+')
start = int(input("Start at what number?"))
end = int(input("End at what number?"))
#open target files
nouns = open("kelen nouns.csv",'a', encoding ='utf-16-le')
etc = open("kelen not nouns.csv", 'a', encoding = 'utf-16-le')
#gather the main page
response = post(url, data={'passed': '', 'QueryType': "Form" })
safe_text = response.text#.translate(non_bmp_map)
html_soup = BeautifulSoup(safe_text, 'html.parser')
#get all the maybe words and their links.
word_links = html_soup.find_all('a', href =re.compile('formlisting'))
i = 0 # for progress
for link in word_links :
	i += 1
	form = link.find("span", class_ = "kelen field").get_text()
	if not not_word.search(form) and i< end and i >= start :
		#look at the page for the specific word.
		url = urlStem + link.get('href')
		time.sleep(2)#to prevent ddosing
		small_response = get(url)
		if small_response.status_code == 429 :
			time.sleep(300)
		elif small_response.status_code != 200 :
			print( "problem ")
			print(small_response.status_code)
		small_soup = BeautifulSoup(small_response.text,'html.parser')
		#get just the part of speech, and ignore the text around it.
		small_soup.h2.a.decompose()#to remove all the fancy kelen
		part_of_speech = find_whitespace.sub("",small_soup.h2.get_text())
		kelen = small_soup.ul.find_all("span",class_ = "kelen")
		#get the stems
		stem = ''
		for txt in kelen : #to only grab the things with one word, specifically a stem
			if len(txt.contents) == 1 and is_stem.search(txt.get_text()) is not None:
				stem += txt.get_text()
		#separate nouns and other parts of speech then store
		if is_noun.search(part_of_speech) :	
			nouns.write(form + ',' + part_of_speech + ',' + stem + '\n')
		else :
			etc.write(form + ',' + part_of_speech + ',' + stem + '\n')
		print(i)
#close the files for safety.			
nouns.close()
etc.close()