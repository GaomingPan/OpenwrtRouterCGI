# Copyright (C) 2006,2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=routerSettings
PKG_VERSION:=1.0.0
PKG_RELEASE:=Beta-1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:= @SF/$(PKG_NAME)
PKG_MD5SUM:=7241d86b46bbfeef54fb72e48a56dc8c

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/routerSettings
  SECTION:=RouterSettings
  CATEGORY:=routerSettings
  DEPENDS:=+uci +libpthread
  TITLE:=A CGI interface to setting the router
  URL:=http://www.wifidog.org
endef

define Package/routerSettings/description
	This software is a simple CGI interface to setting router.
endef

define Package/routerSettings/conffiles
/etc/.ui_info.properties
endef

define Package/routerSettings/install
	$(INSTALL_DIR) $(1)/www_cloud/cgi-bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/routerSettings $(1)/www_cloud/cgi-bin/routerSettings
	$(INSTALL_DIR) $(1)/www_cloud/cgi-bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/scripts/*  $(1)/www_cloud/cgi-bin/
	$(INSTALL_DIR) $(1)/www_cloud/
	$(CP)          $(PKG_BUILD_DIR)/www/index.html $(1)/www_cloud/
	$(INSTALL_DIR) $(1)/www_cloud/pages
	$(CP)          $(PKG_BUILD_DIR)/www/pages/* $(1)/www_cloud/pages/
	$(INSTALL_DIR) $(1)/www_cloud/img
	$(CP)          $(PKG_BUILD_DIR)/www/img/* $(1)/www_cloud/img/
	$(INSTALL_DIR) $(1)/etc
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/ui_info.properties $(1)/etc/.ui_info.properties
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/etc/config/sysinfo_for_browser  $(1)/etc/config/sysinfo_for_browser
endef

$(eval $(call BuildPackage,routerSettings))