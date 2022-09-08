# INSILICO_PRIMER_GEN
The Software aims at optimizing the primer sequence on the basis of the following four factors:

-> Length : 

The length of the primer is kept between 18-30 nucleotides to maintain proper specificity and avoid self-dimerization or non-specific annealing to common stretches of nucleotide sequences.
            
-> Temperature : 

The temperature for annealing needs to be similar for the forward and the reverse primer sequences with no more than a 5 degree celcius difference between the two. The allowed temperature range is from 55-65 degree celcius.

                                                   Tm=81.5+0.41(%GC)−675/N−%mismatch
                                                   
                                                   N = Number of Nucleotides,
                                                   
                                                   %GC = %GC content.
                                                   
                            This is the formula we are using to determine the temperature for our primer design.
                 
-> GC Content : 

The GC content gretly determines the melting temperature and the binding affinity of the primer to the complementary DNA strand.
                                                   %GC= (Number of G + Number of C)/total number of nucleotides
                         
-> Secondary Structure Formation : 

In order to efficiently avoid the formation of the unwanted secondary structures we must ensure there are no Palindromic Complementary sequences in the primer besides repeating nucleotides must be avoided as they may lead to self-dimerization.
                                                                 
INPUT: 

-> The input will consist of the sequence of nucleotides of the gene that needs to be copied using PCR.
 
-> Allowed Temperature Range
        
-> Allowed G/C Content Range
 
OUTPUT: 

The output will consist of the most optimized primer sequence on the basis of the above factors.
 
Development Phase 2 : 

The software would design both the forward and the reverse primer together to prevent palindromic complementaraity between them and prevent their annealing.
 
Development Phase 3 : 

The software would design sequences based on Protein sequences and mRNA sequences besides the DNA sequence.
 
Current Limitations :

-> Trying to accurately estimate the correct number of complementary nucleotides needed to anneal a primer sequence of a specific length to the DNA. This number if precisely determined would greatly help in further optimization and prevention of secondary structure formation.
 
-> Considering the possibility of inducing silent mutations to our sequence in order to optimize the primer functionality especially in the phase of development when we will design primer sequences from RNA and Protein Sequences.
                      
-> Trying to optimize the sequences by shifting bases in the intron sequences as that would not have any effect on the reading frames for the exon sequences and can be a new method of optimization as the code often does not produce optimized sequences within the Temperature and G/C content range. 
