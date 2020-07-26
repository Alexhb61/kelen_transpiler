from requests import post, get
from bs4 import BeautifulSoup, UnicodeDammit
import re
import chardet
import time
#CODE FAILURES
# err_str = r"āēīōūñŋþλ"
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson
#setup constant like things
url = "http://www.terjemar.net/kelen/Dict/sentencelisting.php?id=1"
urlStem = "http://www.terjemar.net/kelen/Dict/sentencelisting.php?id="
start = int(input("Start at what number?"))
end = int(input("End at what number?"))
#open target files
kelenSentences = open("kelen sentences.csv",'a', encoding ='utf-16-le')
englishSentences = open("english sentences.csv",'a', encoding ='utf-16-le')
partsSentences = open("parts sentences.csv",'a', encoding ='utf-16-le')
#gather the main page


for i in range(start, end):
	url = urlStem + str(i)
	response = post(url, data={'passed': '', 'QueryType': "Form" })
	safe_text = response.text#.translate(non_bmp_map)
	html_soup = BeautifulSoup(safe_text, 'html.parser')


	kelenSentences.write(html_soup.find_all('td', class_= 'kelen sent')[0].text + '\n')
	englishSentences.write(html_soup.find_all('td', class_= 'sent')[1].text + '\n')
	linesList = html_soup.find_all('table', class_= 'inner')
	for Line in linesList:
		trs = Line.findChildren('tr')
		tds = trs[1].findChildren('td')
		for td in tds:
			partsSentences.write(td.text+' ')
	partsSentences.write('\n');

kelenSentences.close()
englishSentences.close()
partsSentences.close()