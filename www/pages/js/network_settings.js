/*
*
*
*
* */

function networkSettings_data_binding() {
    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "data_network"
        },
        dataType: "json",
        beforeSend: function () {
        },
        success: function (data) {

            var ret_data = eval(data);
            if (ret_data.network_wan.wan_proto == "static") {

                $("#network_type").html("&nbsp;[&nbsp;当前联网方式:&nbsp;静态&nbsp;IP&nbsp;地址&nbsp;]");

                if ($("#static_ip").is(":checked"))
                    ;
                else
                    $("#static_ip").attr("checked", true);

                $("#objPage > .div-item").css("visibility", "hidden");
                $("#objPage > .div-item").css("display", "none");
                $("#objPage > #div2").css("visibility", "visible");
                $("#objPage > #div2").css("display", "block");

                var ip_str;
                ip_str = ret_data.network_wan.wan_ipaddr;
                $("#ip1").val(ip_str.split(".")[0]);
                $("#ip2").val(ip_str.split(".")[1]);
                $("#ip3").val(ip_str.split(".")[2]);
                $("#ip4").val(ip_str.split(".")[3]);

                ip_str = ret_data.network_wan.wan_netmask;
                $("#netmask1").val(ip_str.split(".")[0]);
                $("#netmask2").val(ip_str.split(".")[1]);
                $("#netmask3").val(ip_str.split(".")[2]);
                $("#netmask4").val(ip_str.split(".")[3]);

                ip_str = ret_data.network_wan.wan_gateway;
                $("#gateway1").val(ip_str.split(".")[0]);
                $("#gateway2").val(ip_str.split(".")[1]);
                $("#gateway3").val(ip_str.split(".")[2]);
                $("#gateway4").val(ip_str.split(".")[3]);

                ip_str = ret_data.network_wan.wan_dns;
                $("#dns1").val(ip_str.split(".")[0]);
                $("#dns2").val(ip_str.split(".")[1]);
                $("#dns3").val(ip_str.split(".")[2]);
                $("#dns4").val(ip_str.split(".")[3]);

            } else if (ret_data.network_wan.wan_proto == "dhcp") {

                $("#network_type").html("&nbsp;[&nbsp;当前联网方式:&nbsp;DHCP&nbsp;客户端&nbsp]");

                if ($("#dhcp").is(":checked"))
                    ;
                else
                    $("#dhcp").attr("checked", true);

                $("#objPage > .div-item").css("visibility", "hidden");
                $("#objPage > .div-item").css("display", "none");
                $("#objPage > #div1").css("visibility", "visible");
                $("#objPage > #div1").css("display", "block");

            } else if (ret_data.network_wan.wan_proto == "pppoe") {

                $("#network_type").html("&nbsp;[&nbsp;当前联网方式:&nbsp;PPPoE&nbsp;拨号&nbsp;]");

                if ($("#pppoe").is(":checked"))
                    ;
                else
                    $("#pppoe").attr("checked", true);

                var str;
                str = ret_data.network_wan.wan_pppoe_username;
                $("#pppoe_username").val(str);
                str = ret_data.network_wan.wan_pppoe_password;
                $("#pppoe_password").val(str);

                $("#objPage > .div-item").css("visibility", "hidden");
                $("#objPage > .div-item").css("display", "none");
                $("#objPage > #div3").css("visibility", "visible");
                $("#objPage > #div3").css("display", "block");

            } else
                alert("Server ERROR !");


        },//success: function (data)
    })
}


function networkSettings_data_post() {
    var proto;
    var ip;
    var netmask;
    var gateway;
    var dns;
    var pppoe_username;
    var pppoe_password;

    ip = $("#ip1").val() + "." + $("#ip2").val() + "." + $("#ip3").val() + "." + $("#ip4").val();
    netmask = $("#netmask1").val() + "." + $("#netmask2").val() + "." + $("#netmask3").val() + "." + $("#netmask4").val();
    gateway = $("#gateway1").val() + "." + $("#gateway2").val() + "." + $("#gateway3").val() + "." + $("#gateway4").val();
    dns = $("#dns1").val() + "." + $("#dns2").val() + "." + $("#dns3").val() + "." + $("#dns4").val();
    pppoe_username = $("#pppoe_username").val();
    pppoe_password = $("#pppoe_password").val();


    if ($("#static_ip").is(":checked"))
        proto = "static";

    if ($("#pppoe").is(":checked"))
        proto = "pppoe";

    if ($("#dhcp").is(":checked"))
        proto = "dhcp";

    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "set_wan",
            wan_proto: proto,
            wan_ip: ip,
            wan_netmask: netmask,
            wan_gateway: gateway,
            wan_dns: dns,
            wan_pppoe_username: pppoe_username,
            wan_pppoe_password: pppoe_password,
        },
        dataType: "json",
        beforeSend: function () {

        },
        success: function (data) {
            var ret = eval(data);
            if (ret.result == 0) {
                alert("OK: 上网设置成功！");
                window.location = "/index.html";
            } else {
                alert("ERROR: 上网设置出错！请重新设置！");
                window.location = "/index.html";
            }
        },//success: function (data)
    });

    // window.location("/index.html");
}


