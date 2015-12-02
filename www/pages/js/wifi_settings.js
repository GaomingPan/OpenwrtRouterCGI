function wireless_data_binding() {

    $.ajax({
            type: "POST",
            url: "/cgi-bin/routerSettings",
            data: {
                form_id: "data_wireless"
            },
            dataType: "json",
            beforeSend: function () {

            },
            success: function (data) {

                var ret = eval(data);

                $("#wifi_ssid").val(ret.ssid);
                $("#wifi_password").val(ret.key);


                if (ret.wifi_status.radio0.up) {

                    $("#wifi").attr("checked", true);
                    $("#objPage > .div-item").css("visibility", "hidden");
                    $("#objPage > .div-item").css("display", "none");
                    $("#objPage > #div2").css("visibility", "visible");
                    $("#objPage > #div2").css("display", "block");


                } else {

                    $("#wifi").attr("checked", false);
                    $("#objPage > .div-item").css("visibility", "hidden");
                    $("#objPage > .div-item").css("display", "none");
                    $("#objPage > #div2").css("visibility", "hidden");
                    $("#objPage > #div2").css("display", "none");

                }


                if (ret.hidden == 1) {
                    $("#ssid_hidden_box").attr("checked", true);
                } else {
                    $("#ssid_hidden_box").attr("checked", false);
                }

                if (ret.encryption == "none") {
                    $("#wifi_passwd_box").attr("checked", false);

                    if ($("#wifi_passwd_box").is(":checked")) {
                        $("#objPage1 > .div-item").css("visibility", "hidden");
                        $("#objPage1 > .div-item").css("display", "none");
                        $("#objPage1 > #div3").css("visibility", "visible");
                        $("#objPage1 > #div3").css("display", "block");

                    }
                    else {

                        $("#objPage1 > .div-item").css("visibility", "hidden");
                        $("#objPage1 > .div-item").css("display", "none");
                        $("#objPage1 > #div3").css("visibility", "hidden");
                        $("#objPage1 > #div3").css("display", "none");
                    }

                } else {
                    $("#wifi_passwd_box").attr("checked", true);

                    if ($("#wifi_passwd_box").is(":checked")) {
                        $("#objPage1 > .div-item").css("visibility", "hidden");
                        $("#objPage1 > .div-item").css("display", "none");
                        $("#objPage1 > #div3").css("visibility", "visible");
                        $("#objPage1 > #div3").css("display", "block");

                    }
                    else {

                        $("#objPage1 > .div-item").css("visibility", "hidden");
                        $("#objPage1 > .div-item").css("display", "none");
                        $("#objPage1 > #div3").css("visibility", "hidden");
                        $("#objPage1 > #div3").css("display", "none");
                    }
                }

            }//success
        }
    )
    ;
//$.ajax
}


function wireless_data_post() {

    var wifi_ssid;
    var wifi_disabled;
    var ssid_hidden;
    var encryption;
    var key;

    $indicator = $('.indicator');
    if ($indicator.hasClass('switch-on')) {
        wifi_disabled = 0;
    } else {
        wifi_disabled = 1;
    }

    if ($("#ssid_hidden_box").is(":checked"))
        ssid_hidden = 1;
    else
        ssid_hidden = 0;

    if ($("#wifi_passwd_box").is(":checked"))
        encryption = "psk2";
    else
        encryption = "none";

    key = $("#wifi_password").val();
    wifi_ssid = $("#wifi_ssid").val();


    $.ajax({
        type: "POST",
        url: "/cgi-bin/routerSettings",
        data: {
            form_id: "set_wireless",
            ssid: wifi_ssid,
            hidden: ssid_hidden,
            encryption: encryption,
            key: key,
            disabled: wifi_disabled,
        },
        dataType: "json",
        beforeSend: function () {

        },
        success: function (data) {

            var ret = eval(data);
            if (ret.result == 0) {
                alert("OK: 无线设置成功！");
                window.location = "/index.html";
            } else {
                alert("ERROR: 无线设置出错！请重新设置！");
                window.location = "/index.html";
            }

        },//success
    });//$.ajax
}