% Generate C++ code for the this function

function output = compile(a)

    %compile - Description
    %
    % Syntax: output = compile(input)
    %
    % Long description
        
    % find nth prime number using the sieve of Eratosthenes and store in output
        sieve = ones(1,a);
        sieve(1) = 0;
        sieve(2) = 0;
        % store the primes in output
        output = [];
        for i = 1:a
            if sieve(i) == 1
                output = [output i];
            end
        end
    
    
    
    
    
    end