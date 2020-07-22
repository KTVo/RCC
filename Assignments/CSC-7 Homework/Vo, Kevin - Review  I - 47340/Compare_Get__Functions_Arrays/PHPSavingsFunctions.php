<?php
class Savings{
	private $pv;
	private $int;
	private $n;
	private $fv;

    public function Savings($pv, $int, $n){
        $this->pv = $pv;
        $this->int = $int;
        $this->n = $n;
    }
    
    
    public function getFV(){
        return $this->fv;
    }

	//Savings with a for-loop
	public function save1(){
		for($year=1;$year<= $this->n;$year++){
			$this->pv*=(1+$this->int);
		}
		return $this->pv;
	}

	//Savings with a power function
	public function save2(){
		return $this->pv*pow(1+$this->int,$this->n);
	}

	//Savings with the exponential-log
	public function save3(){
		return $this->pv*exp($this->n*log(1+$this->int));
	}

	//Savings with recursion
	public function save4($pv,$int,$n){
		if($this->n<=0){return $this->pv;}
		else{return save4($pv,$int,n-1)*(1+$int);}
	}

	//Savings with a default parameter
	function save5(){
		for($year=1;$year<=$this->n;$year++){
			$this->pv*=(1+$this->int);
		}
		return $this->pv;
	}

	//Savings with a reference parameter
	public function save6($pv,$int,$n,&$fv){
		$fv=$pv*exp($n*log(1+$int));
	}

	//Savings with an array
	public function save7(){
		//Declare an array
		$this->fv=array();
		//Fill the array
		$this->fv[0]=$this->pv;
		for($year=1;$year<=$this->n;$year++){
			$this->fv[$year]=$this->fv[$year-1]*(1+$this->int);
		}
		return $this->fv;
	}

	//Display the savings array
	public function display($fv){
		echo '<table width="200" border="1">';
		echo "<tr><th>Year</th><th>Savings</th></tr>";
		for($year=0;$year<count($fv);$year++){
			echo "<tr>";
			echo "<td>".$year."</td>";
			echo "<td>".number_format($fv[$year],2)."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}
}
?>