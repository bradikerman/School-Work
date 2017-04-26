<!DOCTYPE HTML>
<html>
<head>
	<title>Modify Answers</title>
	<meta charset="utf-8"/>
</head>
<body>
<h1>Answer Files</h1>
<h2>Questions</h2>
<p> Answers for the Questions go in the box below in the following format<br>
    A<br>
    B<br>
    These should correlate to the questions before. Please send your friend<br>
    <a href="http://mcs.athens.edu/~sikerman/IkermanASGExam_NewCode.php">This Link</a><br>
</p>
<?php
if($_POST['Submit']){
$open = fopen("MoreAnswers.txt","w+");
$text = $_POST['update'];
fwrite($open, $text);
fclose($open);
echo "Answers updated.<br />";
echo "Answers:<br />";
$file = file("MoreAnswers.txt");
foreach($file as $text) {
echo $text."<br />";
}
}else{
$file = file("MoreAnswers.txt");
echo "<form action=\"".$_SERVER["PHP_SELF"]."\" method=\"post\">";
echo "<textarea Name=\"update\" cols=\"50\" rows=\"10\">";
foreach($file as $text) {
echo $text;
}
echo "</textarea><br>";
echo "<input name=\"Submit\" type=\"submit\" value=\"Update\" />\n
</form>";
}
?>
<form>
        <input type="button" value="Go To New Quiz" onClick="window.location.href='http://mcs.athens.edu/~sikerman/IkermanASGExam_NewCode.php'">
</form>
</body>
</html>

