typedef Point<double> P;
vector<P> polygonCut(const vector<P> &poly, P s, P e){
	vector<P> res;
	rep(i,0,sz(poly)){
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0))
			res.push_back(lineInter(s, e, cur, prev).second);
		if (side)
			res.push_back(cur);
	}
	return res;
}
