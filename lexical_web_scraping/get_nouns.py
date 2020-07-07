from requests import get
from bs4 import BeautifulSoup
# https://www.dataquest.io/blog/web-scraping-beautifulsoup/ lesson

url = "https://www.terjemar.net/kelen/Dict/dictlisting.php"
response = get(url, params={passed: ""})
print(response.text)
html_soup = BeautifulSoup(response.text, 'html.parser')
