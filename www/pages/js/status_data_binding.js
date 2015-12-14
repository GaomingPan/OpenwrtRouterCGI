

setTimeout(function() {
            Push();
    },200);
    //3秒轮询读取函数
    setInterval(function() {
        Push();
    },
    5000);// update check interval 5 seconds 
    //请求函数的ajax
    function Push() {
        $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "data_status",
            },
            beforeSend: function () { },
            dataType: "json",
            success: function (data) {
                var myjson = eval(data);

                if(myjson.result == 1){
                    window.location = "/index.html";
                    return false;
                }

                $("#DeviceId").html(myjson.deviceId);
                $("#DeviceVer").html(myjson.deviceVer);
                $("#OSVersion").html(myjson.osVersion);
                $("#KernelVer").html(myjson.kernelVer);
                $("#Uptime").html(myjson.uptime);
                $("#Sysload").html(myjson.sysload);
                $("#cpu_use").html(myjson.cpu_use + "%");
                $("#_cpu_use").css("width", myjson.cpu_use + "%");
               // $("#total_mem").html("Total:&nbsp" + myjson.memTotal + "&nbspKB");
                $("#MemTotal").css("width", myjson.memTotal + "%");
                $("#MemFree").css("width", myjson.memFree / myjson.memTotal * 100 + "%");
                $("#Buffers").css("width", myjson.buffers / myjson.memTotal * 100 + "%");
                $("#Cached").css("width", myjson.cached / myjson.memTotal * 100 + "%");
                $("#_mem_free").html(parseInt(myjson.memFree / myjson.memTotal * 100) + "%");
                $("#_buffers").html(parseInt(myjson.buffers / myjson.memTotal * 100) + "%");
                $("#_cached").html(parseInt(myjson.cached / myjson.memTotal * 100) + "%");
             }
        });
 }