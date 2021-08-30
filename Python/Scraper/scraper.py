#!/usr/bin/python3.5
import pandas as pd
import smtplib
import os
import email
import filecmp
import ssl
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from bs4 import BeautifulSoup
from urllib.request import urlopen
from urllib.request import urljoin

exist = os.path.isfile("sorted_results.csv")

if exist == True:
	os.rename('sorted_results.csv' , 'oldata.csv')

site = 'http://chico.craigslist.org/search/sga/'
html = urlopen(site)
file = open("results.csv", "w") # "a" to append
file.write("Title,Price,City\n")
counter1 = 0
counter2 = 0
soup = BeautifulSoup(html, 'html.parser')
for listing in soup.find_all('li', class_='result-row'):
	counter1 += 1
	i = listing.find('span', class_='result-price')
	#print(counter1,"value of i = ",i)
	if i != None:
		lines = listing.text.splitlines()
		price = listing.text[3:6]
		name = lines[10]
		city = lines[14]
		city = city.replace("(", "")
		city = city.replace(")", "")
		city = city.replace(" ", "")

		if "," in name:
			name = name.replace(",", "")
		

		if "," not in price and "\nfa" not in price and "fish" in name or "FISH" in name or "Fish" in name:
			price = int(price)
			if price > 20 and price <=250:
				print('HHHHHHHHHHHHHHHHH FOUND HHHHHHHHHHHHHHHHHHHHHHHHHHHHH')
				print(price)
				print(name)
				print(city)

				file.write(name)
				file.write(",")
				file.write(str(price))
				file.write(",")
				file.write(city)
				file.write(" \n")
				
				print("---------------------------")						


file.close()

df = pd.read_csv("results.csv")

sorted_df = df.sort_values(by=["Price"], ascending=True)

sorted_df.to_csv('sorted_results.csv', index=False)


exist2 = os.path.isfile("oldata.csv")

if exist2 == False:
	os.system('touch oldata.csv')

old = "oldata.csv"
new = "sorted_results.csv"

result = filecmp.cmp(old, new)

if result == False:
	subject = "New Listings on Craigslist!"
	body = "Attached are new listings"
	sender_email = "adollarboy@gmail.com"
	receiver_email = "austin.dollar@nevada.unr.edu"
	password = "1Austind"

	message = MIMEMultipart()
	message["From"] = sender_email
	message["To"] = receiver_email
	message["Subject"] = subject 

	message.attach(MIMEText(body, "plain"))

	file_to_attach = "sorted_results.csv"

	attach_file = open(file_to_attach, 'rb')
	payload = MIMEBase('application', 'octate-stream')
	payload.set_payload((attach_file).read())
	encoders.encode_base64(payload) #encode the attachment
	payload.add_header('Content-Disposition', 'attachment', filename=file_to_attach)
	message.attach(payload)

	session = smtplib.SMTP('smtp.gmail.com', 587)
	session.starttls()
	session.login(sender_email, password)
	text = message.as_string()
	session.sendmail(sender_email, receiver_email, text)
	session.quit()
	print('Mail Sent')

	








