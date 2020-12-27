const char WEB_PAGE[] = R"=====(
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset='utf-8'>
      <meta name="keyword" content="html/css, JavaScript, Arduino/ESP8266">
      <title>ESPAP</title>
      <style type="text/css">
         
      </style>
    </head>
    <body>
      <form action="/get">
        SSID: <input type="text" name="SSID">
        <input type="submit" value="Submit">
      </form><br />
      <form action="/get">
        Password: <input type="text" name="Password">
        <input type="submit" value="Submit">
      </form>
    </body>
  </html>
)=====";