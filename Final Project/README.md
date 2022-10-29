# Wommanly 
#### Video Demo:  [(https://youtu.be/tCDzU9SEUYE)
#### Description:
Wommanly is a solution to the major root cause problem prevailing in our society today i.e. RAPE and is encountered by 8 out of 10 persons everyday on an average. Wo-manly is an organization which helps people in times of emergency.

Motive behind this idea is to give assistance to all the persons whenever any situation is about to befall upon them such as sexual assault, violation, molestation, criminal assault, and seduce which is very common these days and is increasing at an alarmimg rate.
**Vision** is to make this society a better place to live in where any person of any gender can freely rome at any pl
**Mission** is to filter out people who makes our society filthy by doing such kind of things that we are all shame on.

The one thing that motivated me for the formation of this organization (which now is a small website) is the increasing filthiness of evil minded people in our society, irrelevant of gender. The kind of things that mankind is doing are unbelievable and shocking to the core.
The amount of suffering the victim has to face after such kind of practice is just immeasurable. Post-traumatic stress disorder (PTSD), including flashbacks, nightmares and severe anxiety are just some of the examples that victims go through.

The functionings are defined in the video, lets discuss about the code.

To implement this idea, I have created a website that uses HTML, CSS, Python, Javascript and it basically runs on **Flask**. My code Contains the following directories:

1. ***Static*** 
Static directory contains all the images and .css files.

2. ***Templates***
Templates directory includes all the templated html files that are being rendered in code namely apology.html, login.html, index.html, layout.html, etc.

3. ***Flask_session***
It contains the flask session.

Except for these, "Final Project" has:
1. ***app.py***
In app.py, all the important flask related session are imported which are needed to implement the code such flask_session from the flask library, generating hash for passwords 
After this, in line 25 configuration from cs50 library to use the sqlite database (womanly.db) has been done.

**4 routes are defined:*

  a) Root Route(/):
     It simply renders index.html template and does nothing else which means that when the user will land on the website, after logging in, directly they will be able      to see the content in index template.
     
  b) Login Route(/login):
     At first, it forgets any user that was previously logged in by clearing the session.
     When the request menthod is POST, it prompts user for username and password, if not provided then it return apology template else the information of user gets          stored in database by using "db.execute". While storing the data, it first convert the password into hash using the hash_generate_password function and meanwhile      if password dosent exists, return apology. Remebering the user, using the session class and redirecting to home page.
     Else, if request method is GET, simply renders the login.html template.
     
  c) Logout Route(/logout):
     Clears the session as in forgets the logged in user and returns to the home page.
     
  d) Register Route(/register):
     If request methos is POST, prompts user for the specific fields, if entered correctly then it gets stored in the database at the backend but if its dosen't gets        the specified field, or the user fails to enter data as asked, it ends by throwing an error, telling the user to register with required fields.
     If everything goes as specified, then user get directed to the root route.


2.***helpers.py***
All the helping functions are defined in this file. Apology is a fn() that renders apology followed by a grumpy cat whenever user fails to give in some basic input as mentioned. The second fn() is the login_required which defines that for some particular route, when user is logged in, only then they will be able to see the further data.

3. ***requirements.txt***
Consists of all the required files while running flask.

4. ***womanly.db***
This is the database which all the user information is being stored.

