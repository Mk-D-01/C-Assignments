const redisUrl = process.env.KV_REST_API_URL;
const redisToken = process.env.KV_REST_API_TOKEN;

async function redis(command) {
    if (!redisUrl || !redisToken) {
        throw new Error("Redis environment variables are not configured");
    }

    const response = await fetch(redisUrl, {
        method: "POST",
        headers: {
            Authorization: `Bearer ${redisToken}`,
            "Content-Type": "application/json"
        },
        body: JSON.stringify(command)
    });

    if (!response.ok) throw new Error("Redis request failed");
    const result = await response.json();
    return result.result;
}

module.exports = async function handler(request, response) {
    if (request.method !== "GET") {
        return response.status(405).json({ error: "Method not allowed" });
    }

    if (request.headers["x-admin-password"] !== (process.env.ADMIN_PASSWORD || "admin123")) {
        return response.status(401).json({ error: "Unauthorized" });
    }

    try {
        const count = await redis(["GET", "dsa:docx:count"]);
        const entries = await redis(["LRANGE", "dsa:docx:users", "0", "499"]);
        return response.status(200).json({
            count: Number(count || 0),
            users: (entries || []).map(entry => JSON.parse(entry))
        });
    } catch (error) {
        console.error(error);
        return response.status(503).json({ error: "Analytics storage unavailable" });
    }
};