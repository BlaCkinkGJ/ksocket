# 
# ksocket project
# BSD-style socket APIs for kernel 2.6 developers
# 
# @2007-2008, China
# @song.xian-guang@hotmail.com (MSN Accounts)
# 
# This code is licenced under the GPL
# Feel free to contact me if any questions
# @2017
# Hardik Bagdi (hbagdi1@binghamton.edu)
# Changes for Compatibility with Linux 4.9 to use iov_iter
# 

CC := gcc

obj-m  := ksocket_udp_srv_demo.o ksocket_udp_cli_demo.o
#ksocket_tcp_srv-objs := ../ksocket.o
CLIENT_OBJS   := usocket_udp_cli_demo.o
SERVER_OBJS   := usocket_udp_srv_demo.o

KDIR   := /lib/modules/$(shell uname -r)/build
PWD    := $(shell pwd)
CLIENT := usocket_cli.out
SERVER := usocket_srv.out

EXTRA_LDFLAGS := -I/home/gndprop/dgist/ksocket/src
KBUILD_EXTRA_SYMBOLS='/home/gndprop/dgist/ksocket/src/Module.symvers'

ifeq ($(ADDRSAFE),true)
	EXTRA_CFLAGS += -DKSOCKET_ADDR_SAFE
endif

all: client server modules

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

client: $(CLIENT_OBJS)
	$(CC) -o $(CLIENT) $^

server: $(SERVER_OBJS)
	$(CC) -o $(SERVER) $^

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf *.ko *.o *.mod.* .H* .tm* .*cmd Module.symvers modules.order $(CLIENT) $(SERVER)

