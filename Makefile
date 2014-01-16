all:custom_auth

custom_auth: user.o token.o BlogUserDatabase.o session.o auth.o custom_auth.o
	g++ user.o token.o BlogUserDatabase.o session.o auth.o custom_auth.o -o custom_auth  -I/usr/local/include -L/usr/local/lib -lwthttp -lwt -lboost_regex -lboost_signals -lboost_system -lboost_thread -lboost_filesystem -lboost_date_time -lwtdbo -lwtdbosqlite3

user.o: user.C
	g++ -g -Wall -c user.C

token.o: token.C
	g++ -g -Wall -c token.C

BlogUserDatabase.o: BlogUserDatabase.C
	g++ -std=c++0x -g -Wall -c BlogUserDatabase.C

session.o: session.C
	g++ -g -Wall -c session.C

auth.o: auth.C
	g++ -g -Wall -c auth.C

custom_auth.o: custom_auth.C
	g++ -g -Wall -c custom_auth.C

clean:
	rm -vf *.o custom_auth

run:
	./custom_auth --docroot . --http-address 0.0.0.0 --http-port 1313 
