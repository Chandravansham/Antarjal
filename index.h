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
        input1: <input type="text" name="input1">
        <input type="submit" value="Submit">
      </form><br />
      <form action="/get">
        input2: <input type="text" name="input2">
        <input type="submit" value="Submit">
      </form><br />
      <form action="/get">
        input3: <input type="text" name="input3">
        <input type="submit" value="Submit">
      </form>
    </body>
  </html>
)=====";