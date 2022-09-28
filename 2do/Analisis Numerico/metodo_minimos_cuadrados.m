%% Introduzca los valores de la tabla para X e Y.
X=[7,1,10,5,4,3,13,10,2];
Y=[2,9,2,5,7,11,2,5,14];
x = 6^(1/3); %<- escribir un valor de x para calcular y(x).

A=[X',ones(length(X),1)];
B=Y';
AA=A'*A;
AB=A'*B;
XX=inv(AA)*AB;


nuevaX = [x,1];
y = nuevaX*XX;
disp('Los coeficionetes a1, a0 son:');disp(XX);
disp(['En x = ',num2str(x),' ; Y = ', num2str(y)]);

%%--------------------------
%% XX = | a1 |
%%      | a0 |

%% y = a0 + a1.x
%%----------------


