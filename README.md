# INSILICO_PCR_Primer_Designer
The Software aims at optimizing the primer sequence on the basis of the following four factors:

-> Length : The length of the primer is kept between 18-30 nucleotides to maintain proper specificity and avoid self-dimerization or non-specific annealing to common stretches of nucleotide sequences.
            
-> Temperature : The temperature for annealing needs to be similar for the forward and the reverse primer sequences with no more than a 5 degree celcius difference between the two. The allowed temperature range is from 55-65 degree celcius.
                                                   Tm=81.5+0.41(%GC)−675/N−%mismatch
                                                   N = Number of Nucleotides,
                                                   %GC = %GC content.
                                This is the formula we are using to determine the temperature for our primer design.
                 
-> GC Content : The GC content gretly determines the melting temperature and the binding affinity of the primer to the complementary DNA strand.
                                                   %GC= (Number of G + Number of C)/total length of primer
                         
-> Secondary Structure Formation : In order to efficiently avoid the formation of the unwanted secondary structures we must ensure there are no Palindromic Complementary sequences in the primer besides repeating nucleotides must be avoided as they may lead to self-dimerization.
                                                                 
 INPUT: The input will consist of the sequence of nucleotides of the gene that needs to be copied using PCR.
 
 OUTPUT: The output will consist of the most optimized forward and reverse primer sequence on the basis of the above factors.
