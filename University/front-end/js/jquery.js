(function($,W,D)
{
    var valid = {};
 
    valid.UTIL =
    {
        setupFormValidation: function()
        {
            //form validation rules
            $("#register-form").validate({
                rules: {
                    email: "Please enter a valid email address",
                    },
                submitHandler: function(form) {
                    form.submit();
                }
            });
        }
    }
 
    //when the dom has loaded setup form validation rules
    $(D).ready(function($) {
        valid.UTIL.setupFormValidation();
    });
 
})(jQuery, window, document);


  $(document).ready(function(){
  $("button").click(function(){
     $.ajax({type: "GET",
        url: "txt/thanks.txt",
        //force to handle it as text
        dataType: "text",
        success: function(result){
            $("#sub").html(result);},
        error: function(error){
            console.log(error);
        }
   
  }});
     )});


  var titles = 
  function titles(text) {
    this._text = text;
    }

  titles.prototype.listingTitles = function (array) {
  for(var number in array) {
    var s = '<li>' + array[number]._text + '</li>';
    var li = document.createElement('li');
    li.innerHTML = s;
    var el=document.getElementById("topSixTitles");
    el.appendChild(li)
  }

};
 var topTitles =  new titles();
topTitles.listingTitles([new titles("Пийте повече вода."), 
    new titles("Заменете нездравословните със здравословни съставки."), 
    new titles("Движете се повече."), 
    new titles("Наспивайте се пълноценно."), 
    new titles("Освобождавайте се от стреса."),
    new titles("Живейте естествено, близо до природата.")]);


function col (nColor) {
    this.col=nColor;
}

col.prototype.changeColor=function () {
    var elem = document.getElementById("water");
    elem.style.color = this.col;
  }

var red=new col("red");

$(document).ready(function(){
    $("#water").mouseover(function(){
        red.changeColor();}
        );
});

