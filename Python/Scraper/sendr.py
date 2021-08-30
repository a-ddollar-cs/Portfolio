import smtplib


server = smtplib.SMTP(host='smtp.gmail.com', port=587)

server.ehlo()

server.starttls()

server.login('austin.dollar@nevada.unr.edu', '1Kaladog')

subject = 'This is my subject'
body = 'This is the message in the email'

message = f'Subject: {subject}\n\n{body}'

server.sendmail('austin.dollar@nevada.unr.edu', 'addollar@protonmail.com', message)
server.quit()
