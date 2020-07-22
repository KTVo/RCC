<!DOCTYPE html>
<!--
    Dr. Mark E. Lehr
    September 11th, 2017
    Include a function library with arrays utilization
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Utilize the Savings PHP Functions</title>
            <?php   include './PHPSavingsFunctions.php';   ?>
    </head>
    <body>
        <?php
            //Declare variables
            $pv=100;   //Present Value $'s
            $int=0.06; //Interest Rate %
            $nYears=12;//Number of compounding periods years

            //Use the function to calculate the value
            $fv1=new Savings($pv,$int,$nYears);//Future Value Calculation
            $fv2=new Savings($pv,$int,$nYears);//Future Value Calculation
            $fv3=new Savings($pv,$int,$nYears);//Future Value Calculation
            $fv4=new Savings($pv,$int,$nYears);//Future Value Calculation
            $fv5=new Savings($pv,$int,$nYears);     //Future Value Calculation
            $fv6;//Declare the future value to be returned
			$fv6_1=new Savings($pv, $int, $nYears);
            $fv6_1->save6($pv,$int,$nYears,$fv6);//Future Value Calculation
            $fv7=new Savings($pv,$int,$nYears);//Future Value Calculation

            //Display results
            echo "<p> Present Value = $".$pv."</p>";
            echo "<p> Interest Rate =  ".($int*100)."%</p>";
            echo "<p> Number of Years =  ".$nYears."(yrs)</p>";
            echo "<p> Future Value 1 = $".number_format($fv1->save1(),2)."</p>";
            echo "<p> Future Value 2 = $".number_format($fv2->save2(),2)."</p>";
            echo "<p> Future Value 3 = $".number_format($fv3->save3(),2)."</p>";
            echo "<p><h5>Note --> there's a \"Fatal error for the recursion method.)\"</h5></p>";
			//echo "<p> Future Value 4 = $".number_format($fv4->save4($pv,$int,$nYears),2)."</p>";
            echo "<p> Future Value 5 = $".number_format($fv5->save5(),2)."</p>";
            echo "<p> Future Value 6 = $".number_format($fv6,2)."</p>";
            $fv7->display($fv7->save7());
        ?>
    </body>
</html>