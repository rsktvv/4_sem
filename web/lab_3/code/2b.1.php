<form action="" method="post" enctype="multipart/form-data">
	<p> имя:<input type="text" name="nam"></p>
	<p> фамилия:<input type="text" name="famul"></p>
	<p> возраст:<input type="text" name="yourNumber"></p>
	<p><input type="submit" value="Сохранить мои данные"></p>
</form>
<?php
	session_start();
	$n=$_POST['nam'];
	$s=$_POST['famul'];
	$q=$_POST['yourNumber'];
	if (isset($n)&&isset($s)&&isset($q)
	{$_SESSION['n']=$n;
	 $_SESSION['s']=$s;
	 $_SESSION['q']=$q;
	}
?>
<p><a href="test.php">Смотреть ваши данные</a></p>
