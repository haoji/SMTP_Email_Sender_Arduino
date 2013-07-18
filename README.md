SMTP Email Sender using Arduino
=========================

A simple SMTP email sender using Arduino

=========================

Auth info:

Run this Perl script to encode your username/password:

perl -MMIME::Base64 -e 'print encode_base64("\000myemail\@myemail.com\000this.should.be.my.password")'
