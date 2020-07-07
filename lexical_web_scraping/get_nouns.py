from requests import post
from bs4 import BeautifulSoup, UnicodeDammit
import re
import chardet



#CODE FAILURES
# err_str = r"āēīōūñŋþλ"
# def swap_encoding(target_str) :
	# return re.sub(r"ā",b'\xC4\x81'.decode('utf-8'),
	# # re.sub(r"ē",chr(275),
	# # re.sub(r"ī",chr(299),
	# # re.sub(r"ō",chr(333),
	# # re.sub(r"ū",chr(363),
	# # re.sub(r"ñ",chr(241),
	# # re.sub(r"ŋ",chr(0x14B),
	# # re.sub(r"þ",chr(354),
	# re.sub(r"λ",chr(955), target_str))
	# #)))))))
#print('\N{Latin Small Letter A with macron}')
# print(swap_encoding(err_str))
# print(err_str)
#non_bmp_map = {
#	r"ā" : "aa",
#	r"ē" : "ee",
#	r"ī" : "ii"
#}
#print();
# print(r"āēīōūñŋþλ".translate(non_bmp_map))
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson

url = "https://www.terjemar.net/kelen/Dict/dictlisting.php"
urlStem = "https://www.terjemar.net/kelen/Dict/"
response = post(url, data={'passed': '', 'QueryType': "Form" })
safe_text = response.text.translate(non_bmp_map)
html_soup = BeautifulSoup(safe_text, 'html.parser')
word_links = html_soup.find_all('a', href =re.compile('formlisting'))
is_word = re.compile('-')

for link in word_links :
	form = link.find("span", class_ = "kelen field").get_text();
	if not is_word.search(form) :
		url = urlStem + link.get('href')
		print(form)