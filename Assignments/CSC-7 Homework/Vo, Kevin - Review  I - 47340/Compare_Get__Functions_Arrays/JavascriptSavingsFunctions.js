function Savings1(pv, int, n){
	this.pv = pv;
	this.int = int;
	this.n = n;
}

function Savings2(pv, int, n){
	this.pv = pv;
	this.int = int;
	this.n = n;
}

function Savings3(pv, int, n){
	this.pv = pv;
	this.int = int;
	this.n = n;
}

function Savings4(pv, int, n){
	this.pv = pv;
	this.int = int;
	this.n = n;
}

function Savings5(pv, int){
	this.pv = pv;
	this.int = int;
	this.n = 12;
}

function Savings6(pv, int, n, fv){
	this.pv = pv;
	this.int = int;
	this.n = n;
	this.fv = fv;
}

function Savings7(pv, int, n){
	this.pv = pv;
	this.int = int;
	this.n = n;
}

//Savings with a for-loop
Savings1.prototype.save1=function(){
    for(var year=1;year<=this.n;year++){
        this.pv*=(1+this.int);
    }
    return this.pv;
};

//Savings with a power function
Savings2.prototype.save2 = function(){
    return this.pv*Math.pow((1+this.int),this.n);
};

//Savings with the exponential-log
Savings3.prototype.save3 = function(){
    return this.pv*Math.exp(this.n*Math.log(1+this.int));
};

//Savings with recursion
Savings4.prototype.save4 = function(){
    if(this.n<=0)return this.pv;
    return Savings4.prototype.save4(this.pv,this.int,this.n-1)*(1+this.int);
};

//Savings with a defaulted parameter
Savings5.prototype.save5 = function(){
    for(var year=1;year<=this.n;year++){
        this.pv*=(1+this.int);
    }
    return this.pv;
};

//Savings with a reference object
Savings6.prototype.save6 = function(){
    this.fv.save=this.pv*Math.exp(this.n*Math.log(1+this.int));
};

//Savings with an array
Savings7.prototype.save7 = function(){
    //Declare an array
    var fv=new Array();
    //Calculate all the values in the array
    fv[0]=this.pv;
    for(var year=1;year<=this.n;year++){
        fv[year]=fv[year-1]*(1+this.int);
    }
    return fv;
};

function Display(){}

//Display the savings array
Display.prototype.display = function(fv){
    //Output the heading for our table
    document.write('<table width="200" border="1">');
    document.write("<tr><th>Years</th><th>Savings</th></tr>");
    for(var year=0;year<fv.length;year++){
        document.write("<tr>");
        document.write("<td>"+year+"</td>");
        var x=1*fv[year];
        document.write("<td>$"+x.toFixed(2)+"</td>");
        document.write("</tr>");
    }
    document.write("</table>");	
};

