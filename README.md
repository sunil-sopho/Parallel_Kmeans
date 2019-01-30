# Parllel_Kmeans

```
COL 380 Jan 27, 2016
```

# 1 k-Means Clustering

K-means clustering is an important algorithm which finds its use in many areas of engineering. The
goal of the algorithm is to findkpartitions (or groups) in an unlabeled set of data points such that
points within a partition have high similarity while the points belonging to different partitions have
low similarity.
More formally, for a set of observations (x 1 ,···, xn), where each observation is ad-dimensional
real vector, k-means clustering aims to group the set of observations in toksets{S 1 ,···, Sk}such
that:


<img style="float: right" src="./kmeans.png" />


## 1.1 Sequential Algorithm

A iterative sequential algorithm is provided for your reference:

1. For a given k, choose k centroids,m 1 ,···, mk. One can resort to Forgy method or Random
    partition method for this initialization.
2. After computing k centroids, assign points to each centroid to form a cluster. Common way to
    assign a point to a centroid is to find the nearest centroid. A point cannot, at any point, belong
    to two different clusters. At the end of this stage, one should have the clusters{S 1 ,···, Sk}.
3. Recompute the mean (or the new centroid)mjfor each clusterSj.
4. Step (3) will require re-partitioning of points since potentially new centroids were computed.
    Repeat steps (2) and (3) until convergence. Convergence conditions can be (i) maximum
    number of iterations, or (ii) if the total number of cluster membership changes in an iteration
    is below a threshold value.

## 1.2 Problem Statement

- Your task is to implement a parallel K-means clustering algorithm where the data points have
    a dimensionality of three and are ofinttype.
- Submit three versions of the code – one sequential, one with Pthreads, and one using OpenMP.
- Perform and plot speed-up and efficiency analysis of parallel implementations by changing the
    input size (i.e., number of threads and size of the dataset) of the problem.
- Submit a report clearly explaining your design decisions, parallelization strategy, loadbalancing
    strategy (if any). Make sure that explanations are bulleted and are not in the form of long
    paragraphs. Keep the lab report within 4 pages.




