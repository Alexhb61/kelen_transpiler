from requests import post, get
from bs4 import BeautifulSoup, UnicodeDammit
import re
import chardet



#CODE FAILURES
# err_str = r"āēīōūñŋþλ"
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson
output = open("kelen words.csv",'x', encoding ='utf-16-le')
url = "https://www.terjemar.net/kelen/Dict/dictlisting.php"
urlStem = "https://www.terjemar.net/kelen/Dict/"
response = post(url, data={'passed': '', 'QueryType': "Form" })
safe_text = response.text#.translate(non_bmp_map)
html_soup = BeautifulSoup(safe_text, 'html.parser')
word_links = html_soup.find_all('a', href =re.compile('formlisting'))
is_word = re.compile('-')

for link in word_links :
	form = link.find("span", class_ = "kelen field").get_text()
	if not is_word.search(form) :
		url = urlStem + link.get('href')
		small_response = get(url)
		small_soup = BeautifulSoup(small_response.text,'html.parser')
		small_soup.h2.a.decompose()
		part_of_speech = small_soup.h2.get_text()
		print(part_of_speech)
		kelen = small_soup.ul.find_all("span",class_ = "kelen")
		stem = ''
		for txt in kelen :
			stem = txt.get_text()
		output.write(form + ',' + part_of_speech + ',' + stem + '\n')
output.close()