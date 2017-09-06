/*
 * hostapd / Station table
 * Copyright (c) 2002-2017, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"

#define ETH_ALEN 6 
struct sta_info {
    unsigned char addr[ETH_ALEN];
    void *ssid;
};

struct hostapd_data {
    int dummy;
};

int ap_for_each_sta(struct hostapd_data *hapd,
		    int (*cb)(struct hostapd_data *hapd, struct sta_info *sta,
			      void *ctx),
		    void *ctx)
{
}


struct sta_info * ap_get_sta(struct hostapd_data *hapd, const unsigned char *sta)
{
	struct sta_info *s = NULL;
	return s;
}

void ap_free_sta(struct hostapd_data *hapd, struct sta_info *sta)
{
}

struct sta_info * ap_sta_add(struct hostapd_data *hapd, const char *addr)
{
	struct sta_info *sta;

	sta = ap_get_sta(hapd, addr);
	if (sta)
		return sta;

	printf("  New STA\n");

	return sta;
}

void ap_sta_disconnect(struct hostapd_data *hapd, const char *addr, unsigned short reason)
{
    struct sta_info *sta;
	if (addr)
		sta = ap_get_sta(hapd, addr);

	if (sta == NULL)
		return;
    /*
     * ...
	 * ap_sta_set_authorized(hapd, sta, 0);
     * ... 
     */
    ap_free_sta(hapd, sta);
}

int sta_cb(struct hostapd_data *hapd, struct sta_info *sta, void *ctx)
{
    printf("STA: "MACSTR"\n", MAC2STR(sta->addr));
    return 0;
}

int main(int argc, char * argv[])
{
    struct hostapd_data hapd;
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x00");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x01");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x02");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x03");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x04");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x05");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x06");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x07");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x08");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x09");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x04\x0a");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x05\x00");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x05\x01");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x05\x02");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x05\x03");
    ap_sta_add(&hapd, "\x00\x01\x02\x03\x05\x04");
    ap_for_each_sta(&hapd, sta_cb, NULL);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x04\x04", 0);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x04\x05", 0);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x04\x06", 0);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x04\x07", 0);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x04\x08", 0);
    ap_sta_disconnect(&hapd, "\x00\x01\x02\x03\x05\x04", 0);
    ap_for_each_sta(&hapd, sta_cb, NULL);
}

