/*
 * measures.h
 *
 * Author: Matteo Magnani <matteo.magnani@it.uu.se>
 * Version: 1.0
 *
 * Social Network Analysis measures for multiplex networks.
 * TESTED:
 * Node based: degree, neighborhood, exclusive neighborhood, relevance, exclusive relevance
 * Layer based: similarity
 *
 * TO BE CONSOLIDATED:
 * Distance based: Pareto distance, Pareto betweenness
 * Group based: modularity
 *
 * References to be added.
 */

#ifndef MLNET_MEASURES_H_
#define MLNET_MEASURES_H_

#include <exception>
#include <string>
#include <unordered_set>
#include "datastructures.h"

namespace mlnet {

/**********************************************************************/
/** Degree  ***********************************************************/
/**********************************************************************/

long degree(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
long degree(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const LayerSharedPtr& layer, edge_mode mode);

double degree_mean(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
double degree_deviation(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const std::unordered_set<LayerSharedPtr>& layers, edge_mode mode);

hashtable<ActorSharedPtr, int> occupation(const MLNetworkSharedPtr& mnet, double teleportation, matrix<double> transitions, int num_steps);

/**********************************************************************/
/** Neighborhood ******************************************************/
/**********************************************************************/

actor_list neighbors(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
actor_list neighbors(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const LayerSharedPtr& layer, edge_mode mode);

actor_list xneighbors(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
actor_list xneighbors(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const LayerSharedPtr& layer, edge_mode mode);

/**********************************************************************/
/** Layer relevance *************************************************/
/**********************************************************************/

double relevance(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
double relevance(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const LayerSharedPtr& layer, edge_mode mode);

double xrelevance(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const u_set<LayerSharedPtr>& layers, edge_mode mode);
double xrelevance(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& actor, const LayerSharedPtr& layer, edge_mode mode);

/**********************************************************************/
/** Layer comparison ************************************************/
/**********************************************************************/

double jaccard_similarity(const MLNetworkSharedPtr& mnet, const std::unordered_set<LayerSharedPtr>& layers);
double jaccard_similarity(const MLNetworkSharedPtr& mnet, const LayerSharedPtr& layer1, const LayerSharedPtr& layer2);

double jaccard_triangle_similarity(const MLNetworkSharedPtr& mnet, const std::unordered_set<LayerSharedPtr>& layers);
double jaccard_triangle_similarity(const MLNetworkSharedPtr& mnet, const LayerSharedPtr& layer1, const LayerSharedPtr& layer2);

double coverage(const MLNetworkSharedPtr& mnet, const LayerSharedPtr& layer1, const LayerSharedPtr& layer2);

double assortativity(const MLNetworkSharedPtr& mnet, const LayerSharedPtr& layer1, const LayerSharedPtr& layer2, edge_mode mode);

// FROM HERE, PORTING NOT COMPLETED YET

/**********************************************************************/
/** Distances *********************************************************/
/**********************************************************************/

hashtable<ActorSharedPtr,std::set<path_length> > pareto_distance(const MLNetworkSharedPtr& mnet, const ActorSharedPtr& from);
/*
std::map<actor_id,std::set<Path> > pareto_distance_all_paths(const MLNetworkSharedPtr& mnet, actor_id vertex);
*/

/**********************************************************************/
/** Betweenness *******************************************************/
/**********************************************************************/

/*
std::map<actor_id,long> pareto_betweenness(const MLNetworkSharedPtr& mnet);

std::map<global_edge_id, long> pareto_edge_betweenness(const MLNetworkSharedPtr& mnet);

int check_dominance(const Distance& d1, const Distance& d2);

int check_dominance(const Path& p1, const Path& p2);

*/

/**********************************************************************/
/** Clustering ********************************************************/
/**********************************************************************/

double modularity(const MLNetworkSharedPtr& mnet, const hashtable<NodeSharedPtr,long>& groups, double c);

} // namespace mlnet

#endif /* MLNET_MEASURES_H_ */
