<!DOCTYPE HTML>
<html>
<head>
<title>Modify Question Files</title>
<meta charset="utf-8"/>
</head>
<body>
<h1>Question Files</h1>
<h2>Questions</h2>
<p> Questions go in the box below and should be in the format<br>
    1. This is your Question? : A) Answer1, B) Answer2<br>
    The 1. is the problem number, followed by the question<br>
    The : allows for the seperation of question and answers<br>
    The answers are seperated by commas.<br>
</p>
<?php
if($_POST['Submit']){
$open = fopen("MoreQuestions.txt","w+");
$text = $_POST['update'];
fwrite($open, $text);
fclose($open);
echo "Questions updated.<br />"; 
echo "Questions:<br />";
$file = file("MoreQuestions.txt");
foreach($file as $text) {
echo $text."<br />";
}
}else{
$file = file("MoreQuestions.txt");
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
        <input type="button" value="Create your Answer File" onClick="window.location.href='http://mcs.athens.edu/~sikerman/IkermanASGExam_NewAnswers.php'">
</form>
</body>
</html>

