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
            beforeSend: function () { },
            dataType: "json",
            success: function (data) { 
	      var ret = eval(data);
	      if(ret.result == 0)
	        wait_for_reset(i);
	      else{
		alter("ERROR: 您的路由器不支持恢复出厂设置!");
		window.location = "/index.html";
	      }
	    },
        });
   
   
}


function wait_for_reset(t){
  
   $("confirm").style.display="";
   var clock = $("clock");
   clock.innerText = "由器恢复出厂设置中…… 请稍等 " + t + "秒钟后刷新浏览器";
   if( i==0 )
     window.location = "/index.html";
   else
     timer = setTimeout("wait_for_reset("+t+"-1)",1000);
}
