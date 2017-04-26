<!DOCTYPE HTML>
<html>
<head>
<title>Are you Smarter than a 5th Grader?</title>
<meta charset="utf-8"/>
</head>
<body>
<h1>Custom Questions</h1>
<?php
function readAnswerKey($filename) {
	$answerKey = array();
	if (file_exists($filename) && is_readable($filename)) {
		$answerKey = file($filename);
	}
	
	return $answerKey;
}
function readQuestions($filename) {
	$displayQuestions = array();
	if (file_exists($filename) && is_readable($filename)) {
		$questions = file($filename);
		foreach ($questions as $key => $value) {
			$displayQuestions[] = explode(":",$value);
		}				
	}
	else { echo "Error finding or reading questions file."; }
	return $displayQuestions;
}
function displayTheQuestions($questions) {
	if (count($questions) > 0 && count($questions) <= 5) {
		foreach ($questions as $key => $value) {
			echo "<b>$value[0]</b><br/><br/>";
			$choices = explode(",",$value[1]);
			foreach($choices as $value) {
				$letter = substr(trim($value),0,1);
				echo "<input type=\"radio\" name=\"$key\" value=\"$letter\">$value<br/>";
			}
			
			echo "<br/>";
		}
	}
	else if(count($questions) >5){
		echo "Too many Questions! Please limit it to 5";
		echo "<br/>";
	}
	else { echo "No questions to display."; }
}
function translateToGrade($percentage) {
	if ($percentage >= 90.0) { return "A"; }
	else if ($percentage >= 80.0) { return "B"; }
	else if ($percentage >= 70.0) { return "C"; }
	else if ($percentage >= 60.0) { return "D"; }
	else { return "F"; }
}
?>

<h2>Are you Smarter than a 5th Grader?</h2>
<h4>Please complete the following questions as accurately as possible.</h4>

<form method="POST" action="<?php echo $_SERVER["PHP_SELF"]; ?>">

<?php
	$loadedQuestions = readQuestions("MoreQuestions.txt");
	displayTheQuestions($loadedQuestions);
?>

<input type="submit" name="submitquiz" value="Submit Quiz"/>
	<input type="button" value="Make your Own" onClick="window.location.href='http://mcs.athens.edu/~sikerman/IkermanASGExam_NewQuestions.php'">
	<input type="button" value="Back to Sample" onClick="window.location.href='http://mcs.athens.edu/~sikerman/IkermanASGExam_Code.php'">
</form> 
<?php
if (isset($_POST['submitquiz'])) {
	$answerKey = readAnswerKey("MoreAnswers.txt");
	$answerCount = count($answerKey);
	$correctCount = 0;
	$Counter = 0;
	foreach ($answerKey as $key => $keyanswer) {
		$Counter++;
		if (isset($_POST[$key])) {
			if (strtoupper(rtrim($keyanswer)) == strtoupper($_POST[$key])) {
				$correctCount++;
			}
			else{
				echo "<font color=\"red\">Number $Counter is incorrect!</font>";
				echo "<br/>";		
			}
		}
	}
	echo "<br/><br/>Total Questions: $answerCount<br/>";
	echo "Number Correct: $correctCount<br/><br/>";
	if ($answerCount > 0) {
		$percentage = round((($correctCount / $answerCount) * 100),1);
		echo "Total Score: $percentage% (Grade: " . translateToGrade($percentage) . ")<br/>";
	}
	else {
		echo "Total Score: 0 (Grade: F)";
	}
}
?>
</body>
</html>
