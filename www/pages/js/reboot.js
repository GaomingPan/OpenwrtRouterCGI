/*

 */

var i = 120;

function reboot_router()
{
   var ret =  confirm("您确定重启动路由器？");
   
   if(!ret)
     return;
   $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "set_reboot",
            },
            beforeSend: function () {
                window.location = "demo_wait.html";
            },
            dataType: "json",
            success: function (data) { },
        });

}

/*****
function wait_for_reboot(t){
  
   $("confirm").style.display="";
   var clock = $("clock");
   clock.innerText = "重启动中…… 请稍等 " + t + "秒钟后刷新浏览器";
   if( i==0 )
     window.location = "/index.html";
   else
     timer = setTimeout("wait_for_reboot("+t+"-1)",1000);
}
*********/

