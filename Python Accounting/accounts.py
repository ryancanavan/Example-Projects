#! /usr/bin/python

import sys
from operator import itemgetter
import time
import os

if len(sys.argv) == 1:
	sys.exit('Must use arguments -i, -h, or -t.')

ACCT_LIST = os.environ.get("ACCT_LIST", None)
f = open(ACCT_LIST, "r")
line = f.readline()
accounts = []
sectionList = line.split(':')
accounts.append(sectionList)
line = f.readline()

while line:
	check = 'unique'
	sectionList = line.split(':')
	for account in accounts:
		if account[0] == sectionList[0]:
			check = account[0]
			if sectionList[3] == 'D':
				balance = float(account[4].rstrip()) + float(sectionList[4].rstrip())
			else:
				balance = float(account[4].rstrip()) - float(sectionList[4].rstrip())
			account[4] = str(balance)
	if check == 'unique':
		if sectionList[3] == 'D':
			accounts.append(sectionList)
			line = f.readline()
		else:
			balance = 0 - float(sectionList[4].rstrip())
			sectionList[4] = str(balance)
			accounts.append(sectionList)
			line = f.readline()
	else:
		line = f.readline()

f.close()

accounts = sorted(accounts, key=itemgetter(1,0))

if str(sys.argv[1]) == '-i':
	while True:
		print 'Info'
		print '----'
		i = 1
		for account in accounts:
			print i, ')', account[1], account[0]
			i = i+1
		print 'q ) quit'
		print '\n'
		choice = raw_input('Enter choice => ')
		if choice == 'q':
			break
		else:
			print '\n'
			print 'account #: ', accounts[int(choice)-1][0]
			print 'name: ', accounts[int(choice)-1][1]
			print 'balance : ', accounts[int(choice)-1][4]
			print '\n'
elif str(sys.argv[1]) == '-h':
	while True:
		print 'History'
		print '-------'
		i = 1
		for account in accounts:
			print i, ')', account[1], account [0]
			i = i+1
		print 'q ) quit'
		print '\n'
		choice = raw_input('Enter choice => ')
		if choice == 'q':
			break
		else:
			print '\n'
			f = open(ACCT_LIST, "r")
			line = f.readline()
			while line:
				sectionList = line.split(':')
				if sectionList[0] == accounts[int(choice)-1][0]:
					if sectionList[3] == 'D':
						print sectionList[2], 'deposit $', sectionList[4]
					else:
						print sectionList[2], 'withdrawal $', sectionList[4]
				line = f.readline()
			f.close()
			print '\n'
elif str(sys.argv[1]) == '-t':
	while True:
		print 'Transaction'
		print '-----------'
		i = 1
		for account in accounts:
			print i, ')', account[1], account[0]
			i = i+1
		print i, ') Add new account'
		print 'q ) quit'
		print '\n'
		choice = raw_input('Enter choice => ')
		if choice == 'q':
			break
		elif int(choice) > len(accounts):
			accountName = raw_input('Account name => ')
			accountId = raw_input('Account number => ')
			for account in accounts:
				if account[0] == accountId:
					sys.exit('Account number already in use')
                        transType = raw_input('Withdrawal or deposit(w or d) => ')
                        if transType == 'w':
                                transAmount = raw_input('Amount to be withdrawn => ')
                                f = open(ACCT_LIST, "a")
                                f.write(accountId + ':' + accountName + ':' + time.strftime("%y.%m.%d") + ':W:' + transAmount + '\n')
                                f.close()
                        elif transType == 'd':
                                transAmount = raw_input('Amount to be deposited => ')
                                f = open(ACCT_LIST, "a")
                                f.write(accountId + ':' + accountName + ':' + time.strftime("%y.%m.%d") + ':D:' + transAmount + '\n')
                                f.close()
                        else:
                                sys.exit('Invalid transaction type.')

		else:
			transType = raw_input('Withdrawal or deposit(w or d) => ')
			if transType == 'w':
				transAmount = raw_input('Amount to be withdrawn => ')
				f = open(ACCT_LIST, "a")
				f.write(accounts[int(choice)-1][0] + ':' + accounts[int(choice)-1][1] + ':' + time.strftime("%y.%m.%d") + ':W:' + transAmount + '\n')
				f.close()
			elif transType == 'd':
				transAmount = raw_input('Amount to be deposited => ')
				f = open(ACCT_LIST, "a")
				f.write(accounts[int(choice)-1][0] + ':' + accounts[int(choice)-1][1] + ':' + time.strftime("%y.%m.%d") + ':D:' + transAmount + '\n')
				f.close()
			else:
				sys.exit('Invalid transaction type.')
else:
	sys.exit('Must use arguments -i, -h, or -t.')
