AddHandler application/x-httpd-ea-php74 .php .php7 .phtml
RewriteCond %{HTTP:X-Forwarded-Proto} !https
RewriteCond %{HTTPS} off
RewriteRule ^ https://%{HTTP_HOST}%{REQUEST_URI} [L,R=301,NE]
RewriteRule ^sensor$ https://ngrok.com/ [L,NC]
RewriteRule ^cam$ https://ngrok.com/ [L,NC]

# php -- BEGIN cPanel-generated handler, do not edit
# “ea-php74” paketini varsayılan “PHP” programlama dili olarak ayarlayın.
<IfModule mime_module>
  AddHandler application/x-httpd-ea-php74 .php .php7 .phtml
</IfModule>
# php -- END cPanel-generated handler, do not edit
