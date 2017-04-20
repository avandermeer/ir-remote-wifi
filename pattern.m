% FORWARD PROPAGATION
% ===================


function p = pattern(numbers)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
%m = size(X, 1);
%num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
%p = zeros(size(X, 1), 1);

% Add ones to the X data matrix
%X = [ones(m, 1) X];

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%

% HIERBIJ GEWOON DIMENSIE ANALYSE, DAN GAAT GOED
% 
% Theta1 = 25 * 401
% Theta2 = 10 * 26
% X = 5000 * 401 (401 door added bias)
% 
% Dus:
% 
% hiddenLayer moet zijn: 5000 * 25 (bij één entry wil je column van 25*1 hebben, maar bij meerdere entries wordt het een matrix, 5000*25)
% h moet zijn (5000 * 26) * (26 * 10) = 5000 * 10
%
% p is dan de hoogste waarde per entry van h 



% =========================================================================



% FIRST: REMOVE DISTORTION

 
length = numel(numbers)
 
values = unique(numbers)
instances = histc(numbers(:),values)



instancesRelative = instances .* (1/length)

    
    percntile = prctile(numbers,5) %5th and 95th percentile
    outlierIndex = numbers < percntile
    %remove outlier values
    numbers
    (outlierIndex) = []
    
    % PAK MAX EN KIJK OF ER IETS IS MET GELIJK AANTAL MET MARGE VAN 10%
    

%SECOND: PATTERN RECOGNITION (LABEL A,B,C ENZ)

    

end
