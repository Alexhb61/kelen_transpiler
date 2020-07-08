from requests import post, get
from bs4 import BeautifulSoup, UnicodeDammit
import re
import chardet



#CODE FAILURES
# err_str = r"āēīōūñŋþλ"
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson
#setup constant like things
url = "https://www.terjemar.net/kelen/Dict/dictlisting.php"
urlStem = "https://www.terjemar.net/kelen/Dict/"
is_word = re.compile('-')
is_noun = re.compile('\[N')
find_whitespace = re.compile('\s+')
#open target files
nouns = open("kelen nouns.csv",'x', encoding ='utf-16-le')
etc = open("kelen not nouns.csv", 'x', encoding = 'utf-16-le')
#gather the main page
response = post(url, data={'passed': '', 'QueryType': "Form" })
safe_text = response.text#.translate(non_bmp_map)
html_soup = BeautifulSoup(safe_text, 'html.parser')
#get all the maybe words and their links.
word_links = html_soup.find_all('a', href =re.compile('formlisting'))
for link in word_links :
	form = link.find("span", class_ = "kelen field").get_text()
	if not is_word.search(form) :
		#look at the page for the specific word.
		url = urlStem + link.get('href')
		sleep(1)#to prevent ddosing
		small_response = get(url)
		small_soup = BeautifulSoup(small_response.text,'html.parser')
		#get just the part of speech, and ignore the text around it.
		small_soup.h2.a.decompose()#to remove all the fancy kelen
		part_of_speech = find_whitespace.sub("",small_soup.h2.get_text())
		kelen = small_soup.ul.find_all("span",class_ = "kelen")
		#get the stems
		stem = ''
		for txt in kelen :
			if len(txt.contents) = 1 : #to only grab the things with one word
				stem += txt.get_text()
		#separate nouns and other parts of speech then store
		if is_noun.search(part_of_speech) :	
			nouns.write(form + ',' + part_of_speech + ',' + stem + '\n')
		else :
			etc.write(form + ',' + part_of_speech + ',' + stem + '\n')
#close the files for safety.			
nouns.close()
etc.close()