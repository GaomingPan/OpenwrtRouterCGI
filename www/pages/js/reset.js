/*

 */

var i = 150;

function reset_router()
{
   var ret =  confirm("您确定使路由器恢复出厂设置？恢复出厂设置后您的配置数据将会被清除。");
   
   if(!ret)
     return;
   $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "set_reset",
            },
            beforeSend: function () {
                window.location = "demo_wait.html";
            },
            dataType: "json",
            success: function (data) { 
	      var ret = eval(data);
	      if(ret.result == 0){

	      }else{
		alert("ERROR: 您的路由器不支持恢复出厂设置!");
		window.location = "/index.html";
	      }
	    },
        });
   
   
}



